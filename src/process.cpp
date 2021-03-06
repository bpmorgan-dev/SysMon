#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// DONE: Return this process's ID
int Process::Pid() { return pid_; }

void Process::Pid(int const p){
  pid_ = p;
}

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() {
  return cpu_;
}

void Process::CpuUtilization(long const activeJiffies, long const totalJiffies){
  float util = (activeJiffies - previousJiffies_) / (totalJiffies - prevTotalJiffies_);
  previousJiffies_ = activeJiffies;
  prevTotalJiffies_ = totalJiffies;
  cpu_ = util;
}

// DONE: Return the command that generated this process
string Process::Command() { return cmd_; }

void Process::Command(string const st){
  cmd_ = st;
}

// DONE: Return this process's memory utilization
string Process::Ram() { return ram_; }

void Process::Ram(std::string const st){
  ram_ = st;
}

// DONE: Return the user (name) that generated this process
string Process::User() { return user_; }

void Process::User(string const st){
  user_ = st;
}

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { return upTime_; }

void Process::UpTime(long const l){
  upTime_ = l;
}

// DONE: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const { return this->cpu_ > a.cpu_; }