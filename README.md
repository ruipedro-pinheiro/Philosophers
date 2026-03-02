*This project has been created as part of the 42 curriculum by rpinheir*

# Description 
	The project "Philosophers" or more well known outside of 42 as the "dining pholosophers problem", is a project were the main notions to learn are mutexes, multi-threading and managing both at the same time. 

	The project is theorical "simple", as one philosopher is one thread, fork is a thread, and the challenge is to provide each thread it's own mutex, so, each philosopher has his own fork but needs allso another fork, which will be the nearbiest. They will have to eat -> sleep -> think, and if they dont eat for some given time, they will die.

# Instructions
bash'''
	make
'''

bash'''
	./philo 5 800 200 200 \[5]
''''

# Resources

Here are some information links that i used to start the project, i inicially allways start from medium or youtube videos for the basic notions like what are threads, differences from threads and processes and also what is a mutex and how to use them.

 1. (CodeVault introduction playlist)[https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2]
 2. (Oceano mutex and threadding introduction)[https://youtu.be/mvZKu0DfFLQ]


