*This project has been created as part of the 42 curriculum by rpinheir*

# Philosophers

The **Dining Philosophers Problem** is a classic concurrency challenge. This project teaches thread management, mutex synchronization, and deadlock prevention in C.

Each philosopher is a thread. Each fork is a mutex. Philosophers must pick up two forks to eat, then sleep, then think. If a philosopher doesn't eat within a given time, they die. The simulation stops when a philosopher dies or when all have eaten enough.

## Instructions

Build from the `philo/` directory:

```bash
cd philo && make
```

Run with the following arguments:

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [max_meals]
```

| Argument | Description |
|----------|-------------|
| `number_of_philosophers` | Number of philosophers and forks |
| `time_to_die` | Time in ms before a philosopher dies without eating |
| `time_to_eat` | Time in ms a philosopher spends eating (holding 2 forks) |
| `time_to_sleep` | Time in ms a philosopher spends sleeping |
| `max_meals` | *(optional)* Simulation stops when all philosophers have eaten this many times |

### Examples

```bash
./philo 5 800 200 200        # No one should die
./philo 1 800 200 200        # One philosopher, dies at 800ms
./philo 4 310 200 100        # A philosopher dies at 310ms
./philo 5 800 200 200 7      # Stops when everyone has eaten 7 times
```

## Resources

1. [CodeVault — Threading & Mutex playlist](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
2. [Oceano — Mutex and threading introduction](https://youtu.be/mvZKu0DfFLQ)

### AI Usage

[Claude Code](https://claude.ai) was used as a debugging and review assistant throughout the project. Specifically:
- Identifying data races and mutex inconsistencies
- Adding doxygen documentation comments
- README formatting and structure

All code was written by me.
