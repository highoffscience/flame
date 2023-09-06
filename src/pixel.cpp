/**
 * @file    pixel.cpp
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#include "pixel.h"

// /**
//  *
//  */
// auto hoso::flame::Pixel::createHisto(uint32 const HistoSize) -> Pixel *
// {
//    // sizeof, not alignof (which yields 8)
//    auto const AlignmentVal = std::align_val_t{sizeof(Pixel)};

//    return new (AlignmentVal) Pixel[HistoSize];
// }

// /**
//  *
//  */
// void hoso::flame::Pixel::destroyHisto(Pixel * const histo_Ptr)
// {
//    // sizeof, not alignof (which yields 8)
//    auto const AlignmentVal = std::align_val_t{sizeof(Pixel)};

//    // no need to call destructors on simple types
//    ::operator delete[] (histo_Ptr, AlignmentVal);
// }
