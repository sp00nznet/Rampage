// RSP Audio microcode HLE for Rampage
#include "librecomp/rsp.hpp"
#include <cstdio>
#include <cstring>

RspExitReason aspMain(uint8_t* rdram, uint32_t ucode_addr) {
    // Read the OSTask from DMEM at 0xFC0
    OSTask task;
    memcpy(&task, &dmem[0xFC0], sizeof(OSTask));

    static int audio_task_count = 0;
    if (audio_task_count < 5) {
        fprintf(stderr, "[AUDIO] Task #%d:\n", audio_task_count);
        fprintf(stderr, "  type=%u flags=0x%x\n", task.t.type, task.t.flags);
        fprintf(stderr, "  ucode=0x%08x ucode_size=%u\n", (uint32_t)task.t.ucode, task.t.ucode_size);
        fprintf(stderr, "  ucode_data=0x%08x ucode_data_size=%u\n", (uint32_t)task.t.ucode_data, task.t.ucode_data_size);
        fprintf(stderr, "  data_ptr=0x%08x data_size=%u\n", (uint32_t)task.t.data_ptr, task.t.data_size);
        fprintf(stderr, "  output_buff=0x%08x output_buff_size=0x%08x\n",
            (uint32_t)task.t.output_buff, (uint32_t)task.t.output_buff_size);
        fprintf(stderr, "  dram_stack=0x%08x dram_stack_size=%u\n",
            (uint32_t)task.t.dram_stack, task.t.dram_stack_size);
        fprintf(stderr, "  yield_data_ptr=0x%08x yield_data_size=%u\n",
            (uint32_t)task.t.yield_data_ptr, task.t.yield_data_size);

        // Dump first 16 words of ucode_data (loaded into DMEM 0x0000)
        fprintf(stderr, "  DMEM[0x000-0x03F] (ucode_data):");
        for (int i = 0; i < 16; i++) {
            uint32_t w = RSP_MEM_W_LOAD(i * 4, 0);
            fprintf(stderr, " %08X", w);
            if (i == 7) fprintf(stderr, "\n                                ");
        }
        fprintf(stderr, "\n");

        // Dump first 16 words of the audio command list (data_ptr in RDRAM)
        if (task.t.data_ptr != 0 && task.t.data_size > 0) {
            fprintf(stderr, "  ABI cmds (data_ptr):");
            uint32_t cmd_addr = (uint32_t)task.t.data_ptr;
            for (int i = 0; i < 16 && i * 4 < (int)task.t.data_size; i++) {
                uint32_t w = MEM_W(0, (int64_t)(int32_t)(cmd_addr + i * 4));
                fprintf(stderr, " %08X", w);
                if (i == 7) fprintf(stderr, "\n                      ");
            }
            fprintf(stderr, "\n");
        }
        fflush(stderr);
    }
    audio_task_count++;

    return RspExitReason::Broke;
}
