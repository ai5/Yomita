# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

ARCH_DEF := -DTARGET_ARCH="$(TARGET_ARCH_ABI)"
ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
  ARCH_DEF += -DIS_64BIT -DIS_ARM
endif

ifeq ($(TARGET_ARCH_ABI),x86_64)
  ARCH_DEF += -DIS_64BIT -DHAVE_SSE4 -msse4.2
endif


LOCAL_MODULE    := Yomita-$(TARGET_ARCH_ABI)
LOCAL_CXXFLAGS  := -std=c++1y -fno-exceptions -fno-rtti -Wextra -Ofast -MMD -MP -fpermissive -D__STDINT_MACROS $(ARCH_DEF)
LOCAL_CXXFLAGS += -fPIE
LOCAL_LDFLAGS += -fPIE -pie
LOCAL_LDLIBS = 
LOCAL_C_INCLUDES := 
LOCAL_CPP_FEATURES += exceptions rtti
#LOCAL_STATIC_LIBRARIES    := -lpthread

LOCAL_SRC_FILES := ../src/main.cpp \
                    ../src/benchmark.cpp ../src/bitboard.cpp ../src/board.cpp ../src/bonapiece.cpp ../src/book.cpp \
                   ../src/common.cpp ../src/eval_kpp.cpp ../src/eval_kppt.cpp ../src/eval_ppt.cpp \
                   ../src/genmove.cpp ../src/gensfen.cpp ../src/haffman.cpp ../src/hand.cpp \
                   ../src/learn.cpp ../src/learn_kppt.cpp ../src/learn_ppt.cpp \
                   ../src/move.cpp ../src/movepick.cpp ../src/multi_think.cpp \
                   ../src/piece.cpp ../src/progress.cpp \
                   ../src/search.cpp ../src/sfen_rw.cpp ../src/shared_memory.cpp ../src/square.cpp \
                   ../src/test.cpp ../src/thread.cpp ../src/timeman.cpp ../src/tt.cpp \
                   ../src/usi.cpp ../src/usioption.cpp

include $(BUILD_EXECUTABLE)
