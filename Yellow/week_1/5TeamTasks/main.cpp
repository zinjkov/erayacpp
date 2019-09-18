//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <unordered_map>
#include <tuple>

using namespace std;
// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const;

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person);

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count);

private:
    map<string, TasksInfo> m_person_task;

    int PerformTask(TasksInfo &tasks, TasksInfo &updated, TasksInfo &old, TaskStatus from, TaskStatus to, int count);
};

const TasksInfo &TeamTasks::GetPersonTasksInfo(const string &person) const {
    return m_person_task.at(person);
}

void TeamTasks::AddNewTask(const string &person) {
    m_person_task[person][TaskStatus::NEW]++;
}

tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const string &person, int task_count) {
    auto &tasks = m_person_task.at(person);
    TasksInfo updated;
    TasksInfo old = tasks;
    task_count = PerformTask(tasks, updated, old, TaskStatus::NEW, TaskStatus::IN_PROGRESS, task_count);
    task_count = PerformTask(tasks, updated, old, TaskStatus::IN_PROGRESS, TaskStatus::TESTING, task_count);
    task_count = PerformTask(tasks, updated, old, TaskStatus::TESTING, TaskStatus::DONE, task_count);
    return {updated, old};
}

int TeamTasks::PerformTask(TasksInfo &tasks, TasksInfo &updated, TasksInfo &old, TaskStatus from, TaskStatus to, int count) {
    while (tasks[from]  && count) {
        tasks[from]--;
        tasks[to]++;
        updated[to]++;
        old[from]--;
        count--;
    }
    return count;
}

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}

//Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
//Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
//Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
//Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done


//Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
//Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
//Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
//Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done