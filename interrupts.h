#include "types.h"
#include "port.h"

#ifndef __INTERUPTS_H
#define __INTERUPTS_H


	class InterruptManager
	{
		
		protected:
			struct GateDescriptor
			{
				uint16_t handleAddressLowBits;
				uint16_t gdt_codeSegmentSelector;
				uint8_t reserved;
				uint8_t access;
				uint16_t handleAddressHighBits;
			} __attribute__((packed));
			
			static GateDescriptor interruptDescriptorTable[256];
			
			struct InterruptDescriptorTablePointer
			{
				uint16_t size;
				uint32_t base;
			} __attribute__((packed));
			
			static void SetInterruptDescriptorTableEntry{
				uint8_t interruptNumber,
				uint16_t codeSegmentSelectorOffset,
				void (*handler)(),
				uint8_t DescriptorPrivilegeLevel,
				uint8_t DescriptorType
			};
		
		
		public:
			InterruptManager(GlobalDescriptorTable* gdt);
			~InterruptManager();
		
			void Activate();
		
			static uint32_t handleInterrupt(uint8_t interruptNumber, uint32_t esp);
			
			static void IgnoreInterruptRequest();
			static void HandleInterruptRequest0x00();
			static void HandleInterruptRequest0x01();
	};

#endif;