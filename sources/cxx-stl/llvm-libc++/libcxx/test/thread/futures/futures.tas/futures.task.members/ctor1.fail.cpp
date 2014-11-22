//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <future>

// class packaged_task<R(ArgTypes...)>
// template <class F>
//   packaged_task(F&& f);
// These constructors shall not participate in overload resolution if 
//    decay<F>::type is the same type as std::packaged_task<R(ArgTypes...)>.

#include <future>
#include <cassert>

struct A {};
typedef std::packaged_task<A(int, char)> PT;
typedef volatile std::packaged_task<A(int, char)> VPT;


int main()
{
    PT p { VPT{} };
}
