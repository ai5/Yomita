﻿/*
読み太（yomita）, a USI shogi (Japanese chess) playing engine derived from
Stockfish 7 & YaneuraOu mid 2016 V3.57
Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad (Stockfish author)
Copyright (C) 2015-2016 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad (Stockfish author)
Copyright (C) 2015-2016 Motohiro Isozaki(YaneuraOu author)
Copyright (C) 2016 Ryuzo Tukamoto

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// 棋譜からの学習時に定義（評価関数、進行度）
//#define LEARN

// 教師棋譜の生成時に定義。
//#define GENSFEN

// 評価関数。
// 使用する場合、以下から一つを定義する。
// 定義しなかった場合、駒得のみの評価関数になる。

// KKP + KPP型
//#define EVAL_KPP

// KPP + 手番型の評価関数
#define EVAL_KPPT

// PP + 手番型の評価関数
//#define EVAL_PPT

// PP + 手番 + 進行度ボーナス
//#define EVAL_PPTP

// KKT + KKPT + KPPT + 進行度ボーナス
//#define EVAL_KPPTP

// 評価関数バイナリの縦横変換を行いたいときに定義する。
//#define CONVERT_EVAL

// 縦型Square用のevalファイルを使いたいときに定義する。
#define USE_FILE_SQUARE_EVAL

// 縦型Squareで作られたハフマン化sfenを読み込みたいときに定義する。
// 読み込み方が対応するだけで、生成には対応しない。
#if !defined(IS_64BIT) || defined(__ANDROID__)
#define GENERATED_SFEN_BY_FILESQ
#endif

// なんらかの評価関数バイナリを使う場合のdefine。
#if defined EVAL_KPP || defined EVAL_KPPT || defined EVAL_PPT || defined EVAL_PPTP || defined EVAL_KPPTP
#define USE_EVAL
#endif

// 進行度を使うときに定義する。
#ifdef USE_EVAL
#define USE_PROGRESS
#endif

// 評価関数バイナリが入っているディレクトリと、学習時に生成したバイナリを保存するディレクトリ
#ifdef EVAL_KPP
#ifdef USE_FILE_SQUARE_EVAL
#define EVAL_TYPE "kpp_file"
#else
#define EVAL_TYPE "kpp"
#endif
#elif defined EVAL_KPPT
#ifdef USE_FILE_SQUARE_EVAL
#define EVAL_TYPE "kppt_file"
#else
#define EVAL_TYPE "kppt"
#endif
#elif defined EVAL_PPT
#define EVAL_TYPE "ppt"
#elif defined EVAL_PPTP
#define EVAL_TYPE "pptp"
#elif defined EVAL_KPPTP
#define EVAL_TYPE "kpptp"
#else
#define EVAL_TYPE "komadoku_only"
#endif

// 評価関数で手番を考慮しているときとそうでないときのdefine。
#if defined EVAL_KPPT || defined EVAL_PPT || defined EVAL_PPTP || defined EVAL_KPPTP
#define USE_EVAL_TURN
#elif defined EVAL_KPP
#define USE_EVAL_NO_TURN
#endif