# Concurrency-and-Parallelism-lab

# 01 Thread
Thread is a lightweight process. If we create multiple threads, then they do not create a copy of process memory like fork instead they add the runtime stack on the memory. Memory can take whole different section for explanation. To utilize thread, you need to initialize the thread and join them. During this event of initializing a thread and calling a work using that thread, this is where the magic of multiple hands happens. Each thread will carry on their work and finish the task. I am going to explore little bit on what happens if multiple threads needs to share information with each other whether it is within the core/processor or with multiple processor.

