cmake_minimum_required(VERSION 3.17)
project(wolprocessor)

set(CMAKE_CXX_STANDARD 17)

add_executable(wolprocessor main.cpp Processor.cpp Processor.h Bus.cpp Bus.h Gate.cpp Gate.h Connection.cpp Connection.h SimpleGates/And.cpp SimpleGates/And.h SimpleGates/LogicLevel.cpp SimpleGates/LogicLevel.h EventLoop.cpp EventLoop.h Circuit.cpp Circuit.h SimpleGates/Or.cpp SimpleGates/Or.h SimpleGates/XOr.cpp SimpleGates/XOr.h Adders/FullAdder.cpp Adders/FullAdder.h Pin.cpp Pin.h Adders/NBitAdder.cpp Adders/NBitAdder.h CircuitItem.cpp CircuitItem.h Adders/ALU.cpp Adders/ALU.h SimpleGates/Not.cpp SimpleGates/Not.h)