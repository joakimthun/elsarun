#pragma once

#include "../typedef.h"

namespace elsa {
    namespace timing {

        class Timer
        {
        public:
            Timer();

            void start();
            void stop();
            void pause();
            void resume();
            u32 get_ticks();
            u32 get_ticks_since_last_call();
            bool is_started();
            bool is_paused();

        private:
            static u32 get_ticks_internal();

            u32 start_ticks_;
            u32 paused_ticks_;
            u32 last_call_ticks_;
            bool paused_;
            bool started_;
        };

    }
}
