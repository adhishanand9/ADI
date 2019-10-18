package Adhish.DS;
import java.io.*;
import java.util.*;
import java.lang.*;

public class CircularlyLinkedList<E> 
{
  //---------------- nested Node class ----------------
  /**
   * Singly linked node, which stores a reference to its element and
   * to the subsequent node in the list.
   */
  private static class Node<E> {

    /** The element stored at this node */
    private E element;     // an element stored at this node

    /** A reference to the subsequent node in the list */
    private Node<E> next=null;  // a reference to the subsequent node in the list

    /**
     * Creates a node with the given element and next node.
     *
     * @param e  the element to be stored
     * @param n  reference to a node that should follow the new node
     */
    public Node(E e, Node<E> n) {
      element=e;
      next=n;
    }

    // Accessor methods
    /**
     * Returns the element stored at the node.
     * @return the element stored at the node
     */
    public E getElement() { return element; }

    /**
     * Returns the node that follows this one (or null if no such node).
     * @return the following node
     */
    public Node<E> getNext() { return next; }

    // Modifier methods
    /**
     * Sets the node's next reference to point to Node n.
     * @param n    the node that should follow this one
     */
    public void setNext(Node<E> n) { next=n; }
  } //----------- end of nested Node class -----------

  // instance variables of the CircularlyLinkedList
  /** The designated cursor of the list */
  private Node<E> tail = null;                  // we store tail (but not head)

  /** Number of nodes in the list */
  private int size = 0;                         // number of nodes in the list

  /** Constructs an initially empty list. */
  public CircularlyLinkedList() { }             // constructs an initially empty list

  // access methods
  /**
   * Returns the number of elements in the linked list.
   * @return number of elements in the linked list
   */
  public int size() { return size; }

  /**
   * Tests whether the linked list is empty.
   * @return true if the linked list is empty, false otherwise
   */
  public boolean isEmpty() { return size==0; }

  /**
   * Returns (but does not remove) the first element of the list
   * @return element at the front of the list (or null if empty)
   */
  public E first() {             // returns (but does not remove) the first element
    if(tail!=null && tail.getNext()!=null)
      return (tail.getNext()).getElement();
    else if(tail!=null)
      return tail.getElement();
    else
      return null;
  }

  /**
   * Returns (but does not remove) the last element of the list
   * @return element at the back of the list (or null if empty)
   */
  public E last() {              // returns (but does not remove) the last element
    if(tail!=null)
      return tail.getElement();
    else
      return null;
   }

  // update methods
  /**
   * Rotate the first element to the back of the list.
   */
  public void rotate() {         // rotate the first element to the back of the list
    if(size >= 1)
      tail = tail.getNext();
  }

  /**
   * Adds an element to the front of the list.
   * @param e  the new element to add
   */
  public void addFirst(E e) {                // adds element e to the front of the list
    Node<E> ptr = new Node<E>(e,null);
      if(tail != null)
        ptr.setNext(tail.getNext());
      else
        tail = ptr;
      tail.setNext(ptr);
      size++;
   }

  /**
   * Adds an element to the end of the list.
   * @param e  the new element to add
   */
  public void addLast(E e) {                 // adds element e to the end of the list
    Node<E> ptr = new Node<E>(e,null);
       if(tail != null) {
          ptr.setNext(tail.getNext());
          tail.setNext(ptr);
       }
       else
          ptr.setNext(ptr);
       tail = ptr;
       size++;
   }

  /**
   * Removes and returns the first element of the list.
   * @return the removed element (or null if empty)
   */
  public E removeFirst() {                   // removes and returns the first element
    if(size == 0)
      return null;
    E e = tail.getNext().getElement();
    if(tail.getNext() == tail)
      tail = null;
    else
      tail.setNext(tail.getNext().getNext());
    size--;
    return e;
   }

  /**
   * Produces a string representation of the contents of the list.
   * This exists for debugging purposes only.
   */
  public String toString() {
    StringBuilder sb=new StringBuilder();
    sb.append("{");
    Node<E> temphead=tail.getNext();
    for(int i=0;i<size;i++) {
      if(i!=0)
        sb.append(", "+temphead.getElement());
      else
        sb.append(temphead.getElement());
        temphead=temphead.getNext();
    }
    sb.append("}");
    return sb.toString();
   }
}