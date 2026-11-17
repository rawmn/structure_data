#pragma once
#include "RingBuffer.h"

//! \brief Печатает состояние кольцевого буфера.
void PrintRingBufferState(RingBuffer& buffer);

//! \brief Меню работы с кольцевым буфером.
void RingBufferMenu(RingBuffer& buffer);
