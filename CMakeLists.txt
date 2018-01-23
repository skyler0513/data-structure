cmake_minimum_required(VERSION 3.9)
project(data_structure C)

set(CMAKE_C_STANDARD 99)

add_executable(data_structure SeqList.c define.h LinkList.c SeqStack.c LinkStack.c SeqQueue.c LinkQueue.c String.c BinaryTree.c Graphic.c)