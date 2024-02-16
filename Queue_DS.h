#ifndef _QUEUEU_DS_H
#define _QUEUEU_DS_H

#include "STD_Queue_Types.h"

typedef struct{
    void **QueueArray;
    uint32 MaxSize;
    uint32 ElementsCount;
    sint32 QueueFront;
    sint32 QueueRear;
}Queue;

/**
  *@brief  : Function to create the Queue and Queue array and initialize it
  *@param  : (MaxSize) The MaxSize of Queue Array
  *@param  : (ret_status) Status of Creation process
  *@return : Return Pointer to the Queue Object
  */
Queue *CreateQueue(uint32 MaxSize, QueueStatus *ret_status);

/**
  *@brief  : Function to insert data to Queue
  *@param  : (queue_obj) Pointer to the Queue to insert data in it
  *@param  : (item_ptr) Pointer to the element to be inserted
  *@return : Return the status of inserting process
  */
QueueStatus EnqueueElement(Queue *queue_obj, void *item_ptr);

/**
  *@brief  : Function to delete data from Queue
  *@param  : (queue_obj) Pointer to the Queue to delete data from it
  *@param  : (item_ptr) Pointer to the element to be deleted
  *@return : Return the status of deleting process
  */
void *DequeueElement(Queue *queue_obj, QueueStatus *ret_status);

/**
  *@brief  : Function to Get the Front element
  *@param  : (queue_obj) Pointer to the Queue to Get element from it
  *@param  : (ret_status) Pointer to the status of Getting process
  *@return : Return (void *) pointer to the Element
  */
void *QueueFront(Queue *queue_obj, QueueStatus *ret_status);

/**
  *@brief  : Function to Get the Rear element
  *@param  : (queue_obj) Pointer to the Queue to Get element from it
  *@param  : (ret_status) Pointer to the status of Getting process
  *@return : Return (void *) pointer to the Element
  */
void *QueueRear(Queue *queue_obj, QueueStatus *ret_status);

/**
  *@brief  : Function to Get Number of elements in the Queue
  *@param  : (queue_obj) Pointer to the Queue to Get Number of elements of it
  *@param  : (QueueCount) Pointer to the Number of Elements
  *@return : Return the status of Getting Process
  */
QueueStatus GetQueueCount(Queue *queue_obj, uint32 *QueueCount);

/**
  *@brief  : Function to destroy Queue Object
  *@param  : (queue_obj) Pointer to the Queue object to be destroyed
  *@return : Return the status of destroying process
  */
QueueStatus DestroyQueue(Queue *queue_obj);

#endif // _QUEUEU_DS_H
