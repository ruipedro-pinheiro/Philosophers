*This project has been created as part of the 42 curriculum by rpinheir*

# Description 
The project **Philosophers** or more well known outside of 42 as the ***dining philosophers problem***, is a project were the main notions to learn are mutexes, multi-threading and managing both at the same time. 

The project is theorical "simple", as one philosopher is one thread and each philosopher fork is a mutexe, and the challenge is to provide each thread it's own mutex, so, each philosopher has his own fork but needs also another fork, which will be the nearbiest. They will have to eat -> sleep -> think, and if they dont eat for some given time, they will die.

# Instructions
#### Build the code with:
```bash
	make
```
<br>
And specify timestamps, while the [5] being optional.<br>
15 = number of philosophers and forks (1 fork for 1 philosopher)<br>
800 = Time in millseconds specifying deadlines for philosophers need to start to eat or they will die.<br>
200 = Time philosophers will be only eating, needing then to hold 2 forks in this delay.<br>
200 = Time philosophers will be spending time sleeping.<br>
<br>
/// OPTIONAL \\\ <br>
5 =   If all philosophers have eaten at least 5 times, the simulation stops<br>

```bash
	./philo 5 800 200 200 \[5]
```

# Resources

Here are some information links that i used to start the project, i inicially allways start from medium or youtube videos for the basic notions like what are threads, differences from threads and processes and also what is a mutex and how to use them.

 1. [CodeVault introduction playlist](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
 2. [Oceano mutex and threadding introduction](https://youtu.be/mvZKu0DfFLQ)


