#include <iostream>
#include <vector>
#include <random>

class Process {
public:
    Process(int pid, int tickets) : pid(pid), tickets(tickets) {}
    int pid;
    int tickets;
    double allocated_tickets; //store the normalized value of tickets
};

class Scheduler {
public:
    void addProcess(Process process) {
        processes.push_back(process);
    }

    void allocateTickets() {
        double total_tickets = 0.0;
        for (const auto& process : processes) {
            total_tickets += process.tickets;
        }
        double allocated_tickets = 0.0;
        // store allocated ticket value in each process
        for (auto& process : processes) {
            allocated_tickets += process.tickets / total_tickets;
            process.allocated_tickets = allocated_tickets;
        }
    }

    Process selectWinner() {    //choose winner
        double rand_num = distribution(generator);  //get random number
        //select process which allocated tickets include rand_num
        for (const auto& process : processes) {
            if (rand_num <= process.allocated_tickets) {
                return process; //selected process is winner and returned
            }
        }
        //error handle: return default process if none is chosen
        return processes[0];
    }

private:
    std::vector<Process> processes; //store processes in vector
    std::random_device rd; //seed for rand num gen
    std::mt19937 generator{rd()}; //rand num gen with value from rd()
    //uniform distribution for randon num gen 0-1
    std::uniform_real_distribution<double> distribution{0.0, 1.0};
};

int main() {
    Scheduler scheduler;

    // Adding processes
    scheduler.addProcess(Process(1, 5));
    scheduler.addProcess(Process(2, 10));
    scheduler.addProcess(Process(3, 3));

    // Allocate tickets
    scheduler.allocateTickets();

    // Select winner
    Process winner = scheduler.selectWinner();
    std::cout << "Process " << winner.pid << " wins the lottery!" << std::endl;

    return 0;
}
