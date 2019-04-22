all:
	$(MAKE) -C Vector
	$(MAKE) -C LinkedList
	$(MAKE) -C SearchTree
	$(MAKE) -C MaxHeap
	$(MAKE) -C HashTable
	$(MAKE) -C QueueArray
	$(MAKE) -C QueueList

clean:
	$(MAKE) clean -C Vector
	$(MAKE) clean -C LinkedList
	$(MAKE) clean -C SearchTree
	$(MAKE) clean -C MaxHeap
	$(MAKE) clean -C HashTable
	$(MAKE) clean -C QueueArray
	$(MAKE) clean -C QueueList
