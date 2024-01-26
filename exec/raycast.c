#include "raycast.h"

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void raycast(t_game *game)
{
	t_player *player;

	player = game->player;

	// DDA에서 사용할 변수. 광선 하나마다 이 값들이 모두 다를 것이다.
	int int_pos_x, int_pos_y; // pos_x, pos_y의 정수버전. 맵 인덱스 접근을 위해 사용
	double plane_x;			  // 광선을 카메라평면으로 쐈을 때 만나는 x 좌표. (실제 '평면'이 아니라 선을 만나는 것이기 때문에 x값으로만 정의해도 된다)
	double ray_xv, ray_yv;	  // 광선 벡터
	// 지금부터 플레이어가 빛을 광선 벡터 방향으로 쏠거다.
	// 빛은 그 길로 나아가면서 격자(맵을 격자로 나눠서 생각)의 세로선(x=1과 평행)과도 만나고, 가로선(y=1과 평행)과도 만난다.
	// 빛이 만나게 될 두 가지 선을 x, y로 분담해서 각각 확인하도록 한다.
	int side;						   // 광선이 현재 만난게 세로선(0)인지 가로선(1)인지 저장.
	double side_dist_x, side_dist_y;   // '맨 처음 side'를 만나기 위해 '광선'이 나아가야 하는 거리. **이후 누적합으로 아래의 delta 변수를 계속해서 더할것이다.
	double delta_dist_x, delta_dist_y; // '다음 side'를 만나기 위해 '광선'이 나아가야 하는 거리. (x == 세로선 사이의 거리) (y == 가로선 사이의 거리)
	int hit;						   // 광선이 wall을 hit했습니까? yes(1) no(0)
	int step_x, step_y;				   // 광선이 현재 격자에서 다음 격자로 한 칸 이동. (DDA 실행 전에 한번만 ray_xv, ray_yv 검사해서 앞으로 빛이 이동할 방향을 정함)
	double perp_wall_dist;			   // perpendicular distance. 어안효과때문에 side_dist 그대로 안 씀
	int wall_height;				   // to_wall_dist에 비례하여 나오는 벽 높이

	int draw_start, draw_end;
	int color;
	// int h = 10; // 벽 높이를 10으로 정규화

	for (int x = 0; x < screenWidth; x++) // 쏠 광선 수 == 전체 화면의 가로 픽셀 수
	{
		plane_x = 2 * x / (double)screenWidth - 1; // 화면의 픽셀 열 (x 좌표)을 정규화하여 [-1,1] 사이의 값으로 매핑.
		// 광선 방향 벡터 구하기
		ray_xv = player->dir_xv + (player->plane_xv * plane_x);
		ray_yv = player->dir_yv + (player->plane_yv * plane_x);
		int_pos_x = (int)(player->pos_x);
		int_pos_y = (int)(player->pos_y);
		//!!공식 유도 이해해야함
		// delta_dist_x = (ray_xv == 0) ? INFINITY : sqrt(1 + (ray_yv * ray_yv) / (ray_xv * ray_xv));
		// delta_dist_y = (ray_yv == 0) ? INFINITY : sqrt(1 + (ray_xv * ray_xv) / (ray_yv * ray_yv));
		delta_dist_x = (ray_xv == 0) ? INFINITY : fabs(1 / ray_xv);
		delta_dist_y = (ray_yv == 0) ? INFINITY : fabs(1 / ray_yv);

		//!!공식 유도 이해해야함
		if (ray_xv < 0)
		{
			step_x = -1;
			side_dist_x = (player->pos_x - int_pos_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (int_pos_x + 1.0 - player->pos_x) * delta_dist_x;
		}

		if (ray_yv < 0)
		{
			step_y = -1;
			side_dist_y = (player->pos_y - int_pos_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (int_pos_y + 1.0 - player->pos_y) * delta_dist_y;
		}

		// 이제 이 광선 하나에 대해 DDA 실행
		hit = 0;
		while (hit == 0) // 장애물(벽) 만날때까지 dist늘려가면서 확인하기
		{
			if (side_dist_x < side_dist_y) // 광선이 세로선과 가깝습니다.
			{
				side_dist_x += delta_dist_x;
				int_pos_x += step_x; // 이때 (사실상) x좌표는 1만큼 이동
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				int_pos_y += step_y;
				side = 1;
			}

			if (game->map_info->map[int_pos_x][int_pos_y] > 0) // Check if ray has hit a wall
				hit = 1;
		}
		//!!공식 유도 이해해야함
		// if (side == 0)
		// 	perp_wall_dist = side_dist_x - delta_dist_x;
		// else
		// 	perp_wall_dist = side_dist_y - delta_dist_y;
		if (side == 0)
			perp_wall_dist = (int_pos_x - player->pos_x + (1 - step_x) / 2) / ray_xv;
		else
			perp_wall_dist = (int_pos_y - player->pos_y + (1 - step_y) / 2) / ray_yv;

		// 내가 구한 광선 길이에 비례하여 세울 벽 높이 결정
		wall_height = (int)(screenHeight / perp_wall_dist);
		// 벽 그릴 픽셀 범위 지정
		draw_start = (screenHeight / 2) + (-wall_height / 2);
		draw_end = (screenHeight / 2) + (wall_height / 2);
		if (draw_start < 0)
			draw_start = 0;
		if (draw_end >= screenHeight)
			draw_end = screenHeight - 1;

		// 벽 색 지정
		switch (game->map_info->map[int_pos_x][int_pos_y])
		{
		case 1:
			color = create_trgb(0, 255, 0, 0);
			break; // red
		case 2:
			color = create_trgb(0, 0, 255, 0);
			break; // green
		case 3:
			color = create_trgb(0, 0, 0, 255);
			break; // blue
		case 4:
			color = create_trgb(0, 255, 255, 255);
			break; // white
		default:
			color = create_trgb(0, 255, 255, 0);
			break; // yellow
		}
		if (side == 1)
			color = color / 2;

		// draw_vertical_line
		while (draw_start < draw_end)
		{
			mlx_pixel_put(game->mlx->p, game->mlx->win, x, draw_start, color);
			draw_start++;
		}
	}
}
