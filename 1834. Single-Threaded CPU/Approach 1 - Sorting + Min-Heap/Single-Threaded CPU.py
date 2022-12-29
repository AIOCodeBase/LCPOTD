class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        next_task: List[Tuple[int, int]] = []
        tasks_processing_order: List[int] = []
        
        sorted_tasks = [(enqueue, process, idx) for idx, (enqueue, process) in enumerate(tasks)]
        sorted_tasks.sort()
        
        curr_time = 0
        task_index = 0
        
        while task_index < len(tasks) or next_task:
            if not next_task and curr_time < sorted_tasks[task_index][0]:
                curr_time = sorted_tasks[task_index][0]
            
            while task_index < len(sorted_tasks) and curr_time >= sorted_tasks[task_index][0]:
                _, process_time, original_index = sorted_tasks[task_index]
                heapq.heappush(next_task, (process_time, original_index))
                task_index += 1
            
            process_time, index = heapq.heappop(next_task)
            
            curr_time += process_time
            tasks_processing_order.append(index)
        
        return tasks_processing_order