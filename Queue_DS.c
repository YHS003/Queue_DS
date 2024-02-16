#include "Queue_DS.h"

/**
  *@brief  : Function to check the Queue is full or not
  *@param  : (queue_obj) Pointer to the Queue object to be checked
  *@return : Return 1 if the Queue is full and 0 if it's not
  */
static uint8 QueueIsFull(Queue *queue_obj)
{
    return (queue_obj->ElementsCount == queue_obj->MaxSize);
}

/**
  *@brief  : Function to check the Queue is empty or not
  *@param  : (queue_obj) Pointer to the Queue object to be checked
  *@return : Return 1 if the Queue is empty and 0 if it's not
  */
static uint8 QueueIsEmpty(Queue *queue_obj)
{
    return (ZERO == queue_obj->ElementsCount);
}

/**
  *@brief  : Function to create the Queue and Queue array and initialize it
  *@param  : (MaxSize) The MaxSize of Queue Array
  *@param  : (ret_status) Status of Creation process
  *@return : Return Pointer to the Queue Object
  */
Queue *CreateQueue(uint32 MaxSize, QueueStatus *ret_status)
{
    Queue *MyQueue = NULL;

    if(!ret_status)
    {
        *ret_status = QUEUE_NULL_POINTER;
        MyQueue = NULL;
    }
    else
    {
        MyQueue = (Queue *)malloc(sizeof(Queue));
        if(!MyQueue)
        {
            MyQueue = NULL;
            *ret_status = QUEUE_NOT_CREATE;
        }
        else
        {
            MyQueue->QueueArray = (void **)calloc(MaxSize, sizeof(void *));
            if(!MyQueue->QueueArray)
            {
                free(MyQueue);
                MyQueue = NULL;
                *ret_status = QUEUE_ARRAY_NOT_CREATE;
            }
            else
            {
                MyQueue->ElementsCount = 0;
                MyQueue->MaxSize = MaxSize;
                MyQueue->QueueFront = -1;
                MyQueue->QueueRear = -1;
                *ret_status = QUEUE_OK;
            }
        }
    }

    return MyQueue;
}

/**
  *@brief  : Function to destroy Queue Object
  *@param  : (queue_obj) Pointer to the Queue object to be destroyed
  *@return : Return the status of destroying process
  */
QueueStatus DestroyQueue(Queue *queue_obj)
{
    QueueStatus status = QUEUE_NOK;

    if(!queue_obj)
    {
        status = QUEUE_NULL_POINTER;
    }
    else
    {
        free(queue_obj->QueueArray);
        free(queue_obj);
        status = QUEUE_DESTROYED;
    }

    return status;
}

/**
  *@brief  : Function to insert data to Queue
  *@param  : (queue_obj) Pointer to the Queue to insert data in it
  *@param  : (item_ptr) Pointer to the element to be inserted
  *@return : Return the status of inserting process
  */
QueueStatus EnqueueElement(Queue *queue_obj, void *item_ptr)
{
    QueueStatus status = QUEUE_NOK;

    if((!queue_obj) || (!item_ptr))
    {
        status = QUEUE_NULL_POINTER;
    }
    else
    {
        if(QueueIsFull(queue_obj))
        {
            status = QUEUE_FULL;
        }
        else
        {
            (queue_obj->QueueRear)++;
            if(queue_obj->QueueRear == queue_obj->MaxSize)
            {
                queue_obj->QueueRear = 0;
            }
            else
            {
                /*Nothing to do*/
            }

            queue_obj->QueueArray[queue_obj->QueueRear] = item_ptr;

            if(ZERO == queue_obj->ElementsCount)
            {
                queue_obj->QueueFront = ZERO;
                queue_obj->ElementsCount = 1;
            }
            else
            {
                (queue_obj->ElementsCount)++;
            }

            status = QUEUE_OK;
        }
    }

    return status;
}

/**
  *@brief  : Function to delete data from Queue
  *@param  : (queue_obj) Pointer to the Queue to delete data from it
  *@param  : (item_ptr) Pointer to the element to be deleted
  *@return : Return the status of deleting process
  */
void *DequeueElement(Queue *queue_obj, QueueStatus *ret_status)
{
    void *RetPtr = NULL;

    if((!queue_obj) || (!ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER;
        RetPtr = NULL;
    }
    else
    {
        if(QueueIsEmpty(queue_obj))
        {
            RetPtr = NULL;
            *ret_status = QUEUE_EMPTY;
        }
        else
        {
            RetPtr = queue_obj->QueueArray[queue_obj->QueueFront];
            (queue_obj->QueueFront)++;
            if(queue_obj->QueueFront == queue_obj->MaxSize)
            {
                queue_obj->QueueFront = 0;
            }
            else
            {
                /*Nothing to do*/
            }
            if(1 == queue_obj->ElementsCount)
            {
                queue_obj->QueueFront = -1;
                queue_obj->QueueRear = -1;
            }
            else
            {
                /*Nothing to do*/
            }
            (queue_obj->ElementsCount)--;
            *ret_status = QUEUE_OK;
        }
    }

    return RetPtr;
}

/**
  *@brief  : Function to Get Number of elements in the Queue
  *@param  : (queue_obj) Pointer to the Queue to Get Number of elements of it
  *@param  : (QueueCount) Pointer to the Number of Elements
  *@return : Return the status of Getting Process
  */
QueueStatus GetQueueCount(Queue *queue_obj, uint32 *QueueCount)
{
    QueueStatus status = QUEUE_NOK;

    if((!queue_obj) || (!QueueCount))
    {
        status = QUEUE_NULL_POINTER;
    }
    else
    {
        *QueueCount = queue_obj->ElementsCount;
        status = QUEUE_OK;
    }

    return status;
}

/**
  *@brief  : Function to Get the Front element
  *@param  : (queue_obj) Pointer to the Queue to Get element from it
  *@param  : (ret_status) Pointer to the status of Getting process
  *@return : Return (void *) pointer to the Element
  */
void *QueueFront(Queue *queue_obj, QueueStatus *ret_status)
{
    void *RetPtr = NULL;

    if((!queue_obj) || (!ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER;
        RetPtr = NULL;
    }
    else
    {
        if(QueueIsEmpty(queue_obj))
        {
            *ret_status = QUEUE_EMPTY;
            RetPtr = NULL;
        }
        else
        {
            RetPtr = queue_obj->QueueArray[queue_obj->QueueFront];
            *ret_status = QUEUE_OK;
        }
    }

    return RetPtr;
}

/**
  *@brief  : Function to Get the Rear element
  *@param  : (queue_obj) Pointer to the Queue to Get element from it
  *@param  : (ret_status) Pointer to the status of Getting process
  *@return : Return (void *) pointer to the Element
  */
void *QueueRear(Queue *queue_obj, QueueStatus *ret_status)
{
    void *RetPtr = NULL;

    if((!queue_obj) || (!ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER;
        RetPtr = NULL;
    }
    else
    {
        if(QueueIsEmpty(queue_obj))
        {
            *ret_status = QUEUE_EMPTY;
            RetPtr = NULL;
        }
        else
        {
            RetPtr = queue_obj->QueueArray[queue_obj->QueueRear];
            *ret_status = QUEUE_OK;
        }
    }

    return RetPtr;
}
