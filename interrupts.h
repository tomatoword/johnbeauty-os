#include "types.h"
#include "port.h"

#ifndef __INTERUPTS_H
#define __INTERUPTS_H


	class InterruptManager
	{
		public:
			static uint32_t handleInterrupt(uint8_t interruptNumber, uint32_t esp);
	};

#endif;