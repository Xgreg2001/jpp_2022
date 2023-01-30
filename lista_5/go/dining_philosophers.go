package main

import (
	"fmt"
	"time"
	"math/rand"
	"sync"
)

const (
	NumPhilosophers = 5
	MaxMeals = 10
	MaxEatTime = 500
	maxThinkTime = 1000
)

type Fork struct {
	c *sync.Cond
	clean bool
	owner int
}

func (f *Fork) request(id int) {
	f.c.L.Lock()
	defer f.c.L.Unlock()
	for f.owner != id {
		
		if !f.clean {
			f.owner = id
			f.clean = true
		} else {
			f.c.Wait()
		}
	}
}

func (f *Fork) release() {
	f.c.L.Lock()
	defer f.c.L.Unlock()
	f.clean = false
	f.c.Broadcast()
}


type Philosopher struct {
	id int
	leftFork *Fork
	rightFork *Fork
}

func (p *Philosopher) dine() {
	eatenMeals := 0

	for eatenMeals < MaxMeals{
		p.think()
		p.eat()
		eatenMeals++

		fmt.Printf("Philosopher %d has eaten %d meals\n", p.id, eatenMeals)
	}

	fmt.Printf("Philosopher %d is done eating\n", p.id)
}

func (p *Philosopher) think() {
	fmt.Printf("Philosopher %d is thinking\n", p.id)
	time.Sleep(time.Millisecond * time.Duration(rand.Intn(maxThinkTime)))
}

func (p *Philosopher) eat() {
	fmt.Printf("Philosopher %d is hungry\n", p.id)

	p.leftFork.request(p.id)
	p.rightFork.request(p.id)

	fmt.Printf("Philosopher %d is eating\n", p.id)
	time.Sleep(time.Duration(rand.Intn(MaxEatTime)) * time.Millisecond)

	p.rightFork.release()
	p.leftFork.release()
}

func main() {
	rand.Seed(time.Now().UnixNano())
	waitGroup := sync.WaitGroup{}
	philosophers := make([]*Philosopher, NumPhilosophers)
	forks := make([]*Fork, NumPhilosophers)

	for i := 0; i < NumPhilosophers; i++ {
		forks[i] = &Fork{sync.NewCond(&sync.Mutex{}), false, i}
	}

	for i := 0; i < NumPhilosophers; i++ {
		philosophers[i] = &Philosopher{i, forks[i], forks[(i+1)%NumPhilosophers]}
	}

	for i := 0; i < NumPhilosophers; i++ {
		waitGroup.Add(1)
		i := i
		go func(){
			defer waitGroup.Done()
			philosophers[i].dine()
		}()
	}

	waitGroup.Wait()
}