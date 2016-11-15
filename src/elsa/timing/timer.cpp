#include "timer.h"

#include <SDL.h>

namespace elsa {
    namespace timing {

        Timer::Timer()
            :
            start_ticks_(0),
            paused_ticks_(0),
            last_call_ticks_(0),
            paused_(false),
            started_(false)
        {
        }

        void Timer::start()
        {
            started_ = true;
            paused_ = false;

            start_ticks_ = get_ticks_internal();
            paused_ticks_ = 0;
        }

        void Timer::stop()
        {
            started_ = false;
            paused_ = false;

            start_ticks_ = 0;
            paused_ticks_ = 0;
        }

        void Timer::pause()
        {
            if (started_ && !paused_)
            {
                paused_ = true;

                paused_ticks_ = get_ticks_internal() - start_ticks_;
                start_ticks_ = 0;
            }
        }

        void Timer::resume()
        {
            if (started_ && paused_)
            {
                paused_ = false;

                start_ticks_ = get_ticks_internal() - paused_ticks_;
                paused_ticks_ = 0;
            }
        }

        u32 Timer::get_ticks()
        {
            if (started_)
            {
                if (paused_)
                {
                    return paused_ticks_;
                }
                else
                {
                    return get_ticks_internal() - start_ticks_;
                }
            }

            return 0;
        }

        u32 Timer::get_ticks_since_last_call()
        {
            auto last_call_ticks = last_call_ticks_;
            last_call_ticks_ = get_ticks();

            return last_call_ticks_ - last_call_ticks;
        }

        bool Timer::is_started()
        {
            return started_;
        }

        bool Timer::is_paused()
        {
            return started_ && paused_;
        }

        u32 Timer::get_ticks_internal()
        {
            return static_cast<u32>(SDL_GetTicks());
        }
    }
}
