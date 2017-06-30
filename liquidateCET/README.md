# How to sell your CET

The rules to liquidate the days in CET bases on the average of your last 3 month salaries.

This is a small program to help you to distribute the days of CET to past 3 month in order to have the best appreciate ratio.

 


# How to run

You have to install docker : 

For MacOS   : https://docs.docker.com/docker-for-mac/install/
For Windows : https://docs.docker.com/docker-for-windows/install/
For Ubuntu  : https://docs.docker.com/engine/installation/linux/docker-ce/ubuntu/
For CentOS  : https://docs.docker.com/engine/installation/linux/docker-ce/centos/


Run command with the number of days in your CET (Don't forget double quotes in the end) : 
'''
docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 bash -c "gcc -o main ./main.c; ./main [Number of Days in CET]"
'''

For example : 
'''
$ docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 bash -c "gcc -o main ./main.c; ./main 26 " 
Starting to processing on 2
1st Mon	|	2nd Mon	|	3rd Mon	|	4th Mon	|	Ratio
7	|	6	|	6	|	7	|	1.842133
'''

