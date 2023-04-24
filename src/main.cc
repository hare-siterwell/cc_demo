#include <stdio.h>

#include "FreeRTOS.h"
#include "hello_shared.h"
#include "hello_static.h"
#include "task.h"

/* 任务参数: 优先级 堆栈大小 任务句柄 任务函数 */
#define START_TASK_PRIO 1
#define START_STK_SIZE  128
TaskHandle_t g_startTaskHandler;
void Start_Task(void *pvParameters);

#define TASK1_TASK_PRIO 2
#define TASK1_STK_SIZE  128
TaskHandle_t g_task1TaskHandler;
void Task1_Task(void *pvParameters);

#define TASK2_TASK_PRIO 3
#define TASK2_STK_SIZE  128
TaskHandle_t g_task2TaskHandler;
void Task2_Task(void *pvParameters);

int main(void)
{
  /* 创建开始任务 */
  xTaskCreate(Start_Task, "start_task", START_STK_SIZE, NULL, START_TASK_PRIO,
              &g_startTaskHandler);

  vTaskStartScheduler();  // 开启任务调度
}

/**
 * @brief 开始任务任务函数
 * @param[in] pvParameters
 */
void Start_Task(void *pvParameters)
{
  taskENTER_CRITICAL();

  /* 创建TASK1任务 */
  xTaskCreate(Task1_Task, "task1_task", TASK1_STK_SIZE, NULL, TASK1_TASK_PRIO,
              &g_task1TaskHandler);

  /* 创建TASK2任务 */
  xTaskCreate(Task2_Task, "task2_task", TASK2_STK_SIZE, NULL, TASK2_TASK_PRIO,
              &g_task2TaskHandler);

  taskEXIT_CRITICAL();

  vTaskDelete(g_startTaskHandler);  // 删除开始任务
}

/**
 * @brief task1任务函数
 * @param[in] pvParameters
 */
void Task1_Task(void *pvParameters)
{
  while (1)
  {
    printf("%s\n", GetStaticText());

    vTaskDelay(200);
  }
}

/**
 * @brief task2任务函数
 * @param[in] pvParameters
 */
void Task2_Task(void *pvParameters)
{
  while (1)
  {
    printf("%s\n", GetSharedText());
    vTaskDelay(300);
  }
}

/**
 * @brief 断言
 * @param[in] ulLine 行数
 * @param[in] pcFileName 文件名
 */
void AssertCalled(unsigned long ulLine, const char *const pcFileName)
{
  volatile uint32_t ulSetToNonZeroInDebuggerToContinue = 0;

  /* Parameters are not used. */
  (void)ulLine;
  (void)pcFileName;

  taskENTER_CRITICAL();
  {
    printf("ASSERT! Line %ld, file %s, GetLastError() %ld\r\n", ulLine,
           pcFileName, GetLastError());
    fflush(stdout);

    /* You can step out of this function to debug the assertion by using the
     * debugger to set ulSetToNonZeroInDebuggerToContinue to a non-zero value.
     */
    while (ulSetToNonZeroInDebuggerToContinue == 0)
    {
      __asm volatile("NOP");
      __asm volatile("NOP");
    }
  }
  taskEXIT_CRITICAL();
}
