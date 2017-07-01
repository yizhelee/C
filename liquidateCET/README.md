# How to sell your CET

The rules to liquidate the days in CET bases on the average of your last 3 month salaries.

This program helps you to understand how to distribute the days of CET to past 3 month and the 4th month in order to have the best ratio.

For some purpose, the progam allows you to calculate the ratio within a period less than 3 month in putting the second input argument.


# How to run

## Run with GCC:

you can run with gcc :
```
gcc -o main ./main.c; ./main Number_of_Days_in_CET Number_of_Month_as_Duration
```

For example :

__For a period of 4 month :__
```
$ gcc -o main ./main.c; ./main 26 4
Starting to processing on 26 days for a period of 4 month
1st Mon	|	2nd Mon	|	3rd Mon	|	4th Mon	|	Ratio
7	|	6	|	6	|	7	|	1.842133
```
__For a period of 3 month :__
```
$ gcc -o main ./main.c; ./main 26 3
Starting to processing on 26 days for a period of 3 month
1st Mon	|	2nd Mon	|	3rd Mon	|	4th Mon	|	Ratio
11	|	5	|	10	|	0	|	1.495567
```


### OR

## Run with Docker without GCC

You have to install docker : 

* For MacOS   : [https://docs.docker.com/docker-for-mac/install/](https://docs.docker.com/docker-for-mac/install/)
* For Windows : [https://docs.docker.com/docker-for-windows/install/](https://docs.docker.com/docker-for-windows/install/)
* For Ubuntu  : [https://docs.docker.com/engine/installation/linux/docker-ce/ubuntu/](https://docs.docker.com/engine/installation/linux/docker-ce/ubuntu/)
* For CentOS  : [https://docs.docker.com/engine/installation/linux/docker-ce/centos/](https://docs.docker.com/engine/installation/linux/docker-ce/centos/)

Run command with the number of days in your CET (__Don't forget double quotes in the end__) : 
```
docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 bash -c "gcc -o main ./main.c; ./main Number_of_Days_in_CET Number_of_Month_as_Duration"
```

For example : 

__For a period of 4 month :__
```
$ docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 bash -c "gcc -o main ./main.c; ./main 26 4" 
Starting to processing on 26 days for a period of 4 month
1st Mon	|	2nd Mon	|	3rd Mon	|	4th Mon	|	Ratio
7	|	6	|	6	|	7	|	1.842133
```
__For a period of 3 month :__
```
$ docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 bash -c "gcc -o main ./main.c; ./main 26 3" 
Starting to processing on 26 days for a period of 3 month
1st Mon	|	2nd Mon	|	3rd Mon	|	4th Mon	|	Ratio
11	|	5	|	10	|	0	|	1.495567
```

