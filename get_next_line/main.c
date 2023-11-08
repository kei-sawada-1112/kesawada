#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int	main(int argc, char **argv)
{
	int fd;
	int i = 0;
	char	*str;
	(void)argc;

	// タイムスタンプを取得して、実行開始時間を記録
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

	fd = open(argv[1], O_RDONLY);
	while (i < 80)
	{
        str = get_next_line(fd);
		printf("%s", str);
		i++;
	}

    // タイムスタンプを取得して、実行終了時間を記録
    gettimeofday(&end_time, NULL);

    // 実行時間を計算
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0;      // sec to ms
    elapsed_time += (end_time.tv_usec - start_time.tv_usec) / 1000.0;   // us to ms

    // メモリ使用量を取得
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    long memory_used = usage.ru_maxrss; // この値はキロバイト(kB)でのメモリ使用量を示す

    printf("Execution time: %f ms\n", elapsed_time);
    printf("Memory used: %ld kB\n", memory_used);

    return 0;
}
