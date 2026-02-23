# Philosophers

> 42 School — Threads, mutexes, and dining philosophers 🍝

## Table of Contents

- [About](#about)
- [The Problem](#the-problem)
- [Rules](#rules)
- [Program Arguments](#program-arguments)
- [Usage](#usage)
- [Implementation](#implementation)
- [Output Format](#output-format)

---

## About

**Philosophers** is a project from the 42 school curriculum that simulates the classic [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem), originally formulated by Edsger Dijkstra. The goal is to learn the basics of concurrent programming, including threads, mutexes, and race conditions.

---

## The Problem

One or more philosophers sit around a round table. There is a large bowl of spaghetti in the middle of the table, with one fork placed between each pair of adjacent philosophers. A philosopher needs **two forks** (the one to their left and the one to their right) to eat. Philosophers alternate between **eating**, **sleeping**, and **thinking**. If a philosopher does not eat within `time_to_die` milliseconds since their last meal (or since the simulation started), they die — and the simulation ends.

---

## Rules

- Each philosopher is a thread.
- There is one fork between each pair of philosophers; the forks are represented by mutexes.
- Philosophers must not die of starvation.
- Philosophers do not communicate with each other.
- Philosophers do not know if another philosopher is about to die.
- When a philosopher has eaten `number_of_times_each_philosopher_must_eat` times (if specified), the simulation stops.

---

## Program Arguments

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument | Description |
|---|---|
| `number_of_philosophers` | The number of philosophers (and forks) at the table |
| `time_to_die` (ms) | Time in milliseconds a philosopher can go without eating before dying |
| `time_to_eat` (ms) | Time in milliseconds it takes a philosopher to eat |
| `time_to_sleep` (ms) | Time in milliseconds a philosopher spends sleeping |
| `number_of_times_each_philosopher_must_eat` | *(Optional)* Simulation ends when every philosopher has eaten at least this many times |

---

## Usage

```bash
# Clone the repository
git clone https://github.com/ruipedro-pinheiro/Philosophers.git
cd Philosophers

# Build the project
make

# Run the simulation
./philo 5 800 200 200

# Run with optional meal count
./philo 5 800 200 200 7
```

---

## Implementation

| Concept | Usage |
|---|---|
| **Threads** | Each philosopher runs in its own POSIX thread (`pthread_t`) |
| **Mutexes** | Each fork is protected by a mutex (`pthread_mutex_t`) to prevent race conditions |
| **Death detection** | A monitoring routine checks timestamps to detect whether a philosopher has exceeded `time_to_die` without eating |
| **Timestamps** | `gettimeofday` is used to track precise elapsed time in milliseconds |

---

## Output Format

Every state change is printed in the following format:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

Where `timestamp_in_ms` is the time elapsed since the simulation started, and `X` is the philosopher's number (starting at 1).

> Messages must not be interleaved or mixed — each log line must be printed atomically.

---

## Notes

- The simulation is written in **C** and compiled with `gcc`.
- No global variables are used.
- Memory is managed carefully — no leaks on exit.
- All threads are properly joined or detached before the program exits.