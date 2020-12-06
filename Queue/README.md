# Queue 
      
 This folder contains the implementaion of Queue using different approches like: using arrays, linked list etc.
      
## What is Queue ?

       Queue is a data structure that uses the rule of FIFO (First In First Out) that means data is added from one end(rear) 
       and is deleted from other end(front).
       
## Operations

The basic operations of the queue are:
* Enqueue(Add an element at the end of the queue)
* Dequeue(Remove an element from the start of the queue)
* Display(Prints the Queue)

## Implementaions
The Queue can be implemented in number of ways using: 

* Array 
* Circular Array 
* Single Linked List
* Double Linked List 
* Circular Linked List

## How to use
In order to use the data structure in your project follow the steps below:

* Open the desired .cpp file remove the main function from the program.
* Move the .cpp file to current working directory of your project.
* Iclude the .cpp file in project you want to include like:

           #include "Queue(Array).cpp"
* Create an object of the Queue class in the project as:

           Queue Q;
* Now call the functions as:

         Q.Enqueue();
         Q.Dequeue();
