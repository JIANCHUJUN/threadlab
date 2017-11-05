
static struct deque{
	void * array; // test list
	int capacity;
	int head;
	int tail;
	int count;
	
};
void init_deque(struct deque * de, int capa)
{
	de->capacity = capa;
	de->array = calloc(de->capacity, sizeof(void *));
	de->head = 0;
	de->tail = 0;
	de->count = 0;
}
//if posi == 0, add before header
//if posi == 1, add after tail
void add_deque(struct deque * de, fork_join_task_t task, int posi)
{
	if (de->count >= de->capacity)
	{
		return;
	}
	if (posi == 1)
		de->array[de->tail] = task;
		de->tail = (de->tail + 1)%de->capacity;
	else
		de->head = (de->head - 1)%de->capacity;
		de->array[de->head] = task;
	de->count++;
		
}

void delete_deque(struct deque * de, fork_join_task_t task, int posi)
{
	if (de->count <= 0)
	{
		return;
	}
	if (posi == 1)
		de->tail = (de->tail - 1)%de->capacity;
		de->array[de->tail] = NULL;
	else
		de->array[de->head] = NULL;
		de->head = (de->head + 1)%de->capacity;
	de->count--;
}

void free_deque(struct deque * de)
{
	free(de->array);
}





struct thread_pool{
	int number;
	p_thread[] thread_array;//
	fork_job_task_t[] task_array;//可能element应该是function和data的二元array？
};









































