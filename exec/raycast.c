#include "raycast.h"


#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// done
int done()
{
	if (keyDown("Escape"))
		return (1);
	return (0);
}

// read_keys





int main(int argc, char **argv)
{
	double pos_x, pos_y; 				// 캐릭터 위치(좌표)
	double dir_xv, dir_yv; 				// 캐릭터 벡터
	double plane_xv, plane_yv;			// 카메라평면 벡터(카메라 평면 == 플레이어가 게임창으로 보는 전경 == 게임창)
	
	pos_x = 22;
	pos_y = 12;

	// (캐릭터 벡터 > 카메라평면 벡터) 그래서 FOV 는 90°보다 작다(1:1일 때 90°)
	dir_xv = -1; 		//데카르트 좌표계 기준 왼쪽 방향
	dir_yv = 0;
	plane_xv = 0;
	plane_yv = 0.66; 	//데카르트 좌표계 기준 위쪽 방향


	// DDA에서 사용할 변수. 광선 하나마다 이 값들이 모두 다를 것이다.
	int int_pos_x, int_pos_y; 			// pos_x, pos_y의 정수버전. 맵 인덱스 접근을 위해 사용
	double plane_x; 					// 광선을 카메라평면으로 쐈을 때 만나는 x 좌표. (실제 '평면'이 아니라 선을 만나는 것이기 때문에 x값으로만 정의해도 된다)
	double ray_xv, ray_yv; 				// 광선 벡터
	// 지금부터 플레이어가 빛을 광선 벡터 방향으로 쏠거다.
	// 빛은 그 길로 나아가면서 격자(맵을 격자로 나눠서 생각)의 세로선(x=1과 평행)과도 만나고, 가로선(y=1과 평행)과도 만난다. 
	// 빛이 만나게 될 두 가지 선을 x, y로 분담해서 각각 확인하도록 한다.
	int side; 							// 광선이 현재 만난게 세로선(0)인지 가로선(1)인지 저장. 
	double side_dist_x, side_dist_y; 	// '맨 처음 side'를 만나기 위해 '광선'이 나아가야 하는 거리. **이후 누적합으로 아래의 delta 변수를 계속해서 더할것이다.
	double delta_dist_x, delta_dist_y; 	// '다음 side'를 만나기 위해 '광선'이 나아가야 하는 거리. (x == 세로선 사이의 거리) (y == 가로선 사이의 거리)
	int hit; 							// 광선이 wall을 hit했습니까? yes(1) no(0)
	int step_x, step_y; 				// 광선이 현재 격자에서 다음 격자로 한 칸 이동. (DDA 실행 전에 한번만 ray_xv, ray_yv 검사해서 앞으로 빛이 이동할 방향을 정함)
	double perp_wall_dist;				// perpendicular distance. 어안효과때문에 side_dist 그대로 안 씀
	int wall_height;					// to_wall_dist에 비례하여 나오는 벽 높이
	
	int draw_start, draw_end;
	double frame_time;					// frameTime은 현재 프레임이 나오는 데 걸린 시간(초)입니다.
	double move_speed, rotate_speed;
	int color;
	double time = 0, oldtime = 0; 		// 현재 및 이전 프레임의 시간을 저장. 둘의 시간차는 특정키를 눌렀을 때 (프레임 계산하는데 얼마나 걸리건 일정한 속도로 움직이기 위해) 이동거리를 결정하고, FPS를 측정하는데 사용할 것입니다.

	t_vars vars;
	t_data data;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "cub3D");
	data.img = mlx_new_image(vars.mlx, screenWidth, screenHeight);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line, &data.endian);

	while (!done()) //화면 렌더링
	{
		for (int x = 0; x < screenWidth; x++) //쏠 광선 수 == 전체 화면의 가로 픽셀 수
		{
			plane_x = 2 * x / (double)screenWidth - 1; //화면의 픽셀 열 (x 좌표)을 정규화하여 [-1,1] 사이의 값으로 매핑.
			//광선 방향 벡터 구하기
			ray_xv = dir_xv + (plane_xv * plane_x);
			ray_yv = dir_yv + (plane_yv * plane_x);
			int_pos_x = (int)pos_x;
			int_pos_y = (int)pos_y;
			//!!공식 유도 이해해야함
			delta_dist_x = (ray_xv == 0) ? INFINITY : sqrt(1 + (ray_yv * ray_yv) / (ray_xv * ray_xv));
			delta_dist_y = (ray_yv == 0) ? INFINITY : sqrt(1 + (ray_xv * ray_xv) / (ray_yv * ray_yv));
			// delta_dist_x = (ray_xv == 0) ? INFINITY : fabs(1 / ray_xv); 
			// delta_dist_y = (ray_yv == 0) ? INFINITY : fabs(1 / ray_yv);

			//!!공식 유도 이해해야함
			if (ray_xv < 0)
			{
				step_x = -1;
				side_dist_x = (pos_x - int_pos_x) * delta_dist_x;
			}
			else
			{
				step_x = 1;
				side_dist_x = (int_pos_x + 1.0 - pos_x) * delta_dist_x;
			}

			if (ray_yv < 0)
			{
				step_y = -1;
				side_dist_y = (pos_y - int_pos_y) * delta_dist_y;
			}
			else
			{
				step_y = 1;
				side_dist_y = (int_pos_y + 1.0 - pos_y) * delta_dist_y;
			}

			//이제 이 광선 하나에 대해 DDA 실행
			while (hit == 0) //장애물(벽) 만날때까지 dist늘려가면서 확인하기
			{
				if (side_dist_x < side_dist_y) //광선이 세로선과 가깝습니다.
				{
					side_dist_x += delta_dist_x;
					int_pos_x += step_x; //이때 (사실상) x좌표는 1만큼 이동
					side = 0;
				}
				else
				{
					side_dist_y += delta_dist_y;
					int_pos_y += step_y;
					side = 1;
				}
				if (worldMap[int_pos_x][int_pos_y] > 0) // Check if ray has hit a wall
					hit = 1;
			}
			//!!공식 유도 이해해야함
			if (side == 0)
				perp_wall_dist = (int_pos_x - pos_x + (1 - step_x) / 2) / ray_xv;
			else
				perp_wall_dist = (int_pos_y - pos_y + (1 - step_y) / 2) / ray_yv;
			
			// 내가 구한 광선 길이에 비례하여 세울 벽 높이 결정
			wall_height = (int)(screenHeight / perp_wall_dist);
			// 벽 그릴 픽셀 범위 지정
			draw_start = (screenHeight / 2) - (wall_height / 2);
			draw_end = (screenHeight / 2) + (wall_height / 2);
			if (draw_start < 0) draw_start = 0;
			if (draw_end > screenHeight) draw_end = wall_height - 1;

			// 벽 색 지정
			switch(worldMap[int_pos_x][int_pos_y])
			{
				case 1:  color = create_trgb(0, 255, 0, 0);    break; //red
				case 2:  color = create_trgb(0, 0, 255, 0);    break; //green
				case 3:  color = create_trgb(0, 0, 0, 255);    break; //blue
				case 4:  color = create_trgb(0, 255, 255, 255); break; //white
				default: color = create_trgb(0, 255, 255, 0); break; //yellow
			}
			if (side == 1)
				color = color / 2;

			// draw_vertical_line
			while (draw_start < draw_end)
			{
				mlx_pixel_put(vars.mlx, vars.win, x, draw_start, color);
				draw_start++;
			}
		}

		// FPS 출력 !!이해해야함
		// 레이캐스팅 loop를 마친 후, 현재 프레임과 이전 프레임의 시간을 계산합니다.
		// 이 시간은 특정 키를 눌렀을 때 (프레임 계산하는데 얼마나 걸리건 일정한 속도로 움직이기 위해) 이동거리를 결정하고, FPS를 측정하는데 사용할 것입니다.
		// oldtime = time;
		// time = get_time();
		// frame_time = (time - oldtime) / 1000.0; //frame_time은 초 단위입니다.
		// // print(1.0 / frame_time, 0, 0); //FPS 출력
		// redraw(); // 왜 다시 그려야하는지 모르겠음
		// cls(); //화면 지우기
		mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);

		move_speed = frame_time * 5.0; //the constant value is in squares/second
		rotate_speed = frame_time * 3.0; //the constant value is in radians/second
		read_keys(); //키보드 입력 받기

		//키보드 입력에 따라 캐릭터 이동
		if (keyDown("W"))
		{
			if (worldMap[(int)(pos_x + dir_xv * move_speed)][(int)pos_y] == 0) pos_x += dir_xv * move_speed;
			if (worldMap[(int)pos_x][(int)(pos_y + dir_yv * move_speed)] == 0) pos_y += dir_yv * move_speed;
		}
		if (keyDown("S"))
		{
			if (worldMap[(int)(pos_x - dir_xv * move_speed)][(int)pos_y] == 0) pos_x -= dir_xv * move_speed;
			if (worldMap[(int)pos_x][(int)(pos_y - dir_yv * move_speed)] == 0) pos_y -= dir_yv * move_speed;
		}
		if (keyDown("D")) //rotate camera plane
		{
			//both camera direction and camera plane must be rotated
			double old_dir_xv = dir_xv;
			dir_xv = dir_xv * cos(-rotate_speed) - dir_yv * sin(-rotate_speed);
			dir_yv = old_dir_xv * sin(-rotate_speed) + dir_yv * cos(-rotate_speed);
			double old_plane_xv = plane_xv;
			plane_xv = plane_xv * cos(-rotate_speed) - plane_yv * sin(-rotate_speed);
			plane_yv = old_plane_xv * sin(-rotate_speed) + plane_yv * cos(-rotate_speed);
		}
		if (keyDown("A")) //rotate camera plane
		{
			//both camera direction and camera plane must be rotated
			double old_dir_xv = dir_xv;
			dir_xv = dir_xv * cos(rotate_speed) - dir_yv * sin(rotate_speed);
			dir_yv = old_dir_xv * sin(rotate_speed) + dir_yv * cos(rotate_speed);
			double old_plane_xv = plane_xv;
			plane_xv = plane_xv * cos(rotate_speed) - plane_yv * sin(rotate_speed);
			plane_yv = old_plane_xv * sin(rotate_speed) + plane_yv * cos(rotate_speed);
		}
	}
}