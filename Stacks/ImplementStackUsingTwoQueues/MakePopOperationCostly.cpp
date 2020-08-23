/*

Method 2 (By making pop operation costly)
In push operation, the new element is always enqueued to q1. In pop() operation, if q2 is empty then all the elements except the last, are moved to q2.
Finally the last element is dequeued from q1 and returned.

1. push(s, x) operation:
 * Enqueue x to q1 (assuming size of q1 is unlimited).
2. pop(s) operation:
 * One by one dequeue everything except the last element from q1 and enqueue to q2.
 * Dequeue the last item of q1, the dequeued item is result, store it.
 * Swap the names of q1 and q2
 * Return the item stored in step 2.
 
*/
