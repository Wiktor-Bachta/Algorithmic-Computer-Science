package main

import (
	"fmt"
	"sync"
	"time"
)

var eatWgroup sync.WaitGroup

type fork struct{ sync.Mutex }

type philosopher struct {
	id                  int
	leftFork, rightFork *fork
	isLeftHanded        bool
}

func (p philosopher) eat() {
    defer eatWgroup.Done()
    for j := 0; j < 3; j++ {
        var firstFork, secondFork *fork
        if p.isLeftHanded {
            firstFork = p.leftFork
            secondFork = p.rightFork
        } else {
            firstFork = p.rightFork
            secondFork = p.leftFork
        }

        say("thinking", p.id)
        time.Sleep(time.Second)

        firstFork.Lock()
        say("picked up first fork", p.id)

        secondFork.Lock()
        say("picked up second fork", p.id)

        say("eating", p.id)

        secondFork.Unlock()
        say("put down second fork", p.id)

        firstFork.Unlock()
        say("put down first fork", p.id)

        say("finished eating", p.id)
    }
}

func say(action string, id int) {
	fmt.Printf("Philosopher #%d is %s\n", id+1, action)
}

func main() {

	count := 5

	forks := make([]*fork, count)
	for i := 0; i < count; i++ {
		forks[i] = new(fork)
	}

	philosophers := make([]*philosopher, count)
	for i := 0; i < count; i++ {
		isLeftHanded := i%2 == 0 
		philosophers[i] = &philosopher{
			id: i, leftFork: forks[i], rightFork: forks[(i+1)%count], isLeftHanded: isLeftHanded}
		eatWgroup.Add(1)
		go philosophers[i].eat()

	}
	eatWgroup.Wait()

}
