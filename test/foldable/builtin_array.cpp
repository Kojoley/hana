/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/comparable.hpp>
#include <boost/hana/foldable.hpp>

#include <laws/base.hpp>
#include <laws/foldable.hpp>
using namespace boost::hana;


int main() {
    int a[] = {1};
    int b[] = {1, 2};
    int c[] = {1, 2, 3};
    int d[] = {1, 2, 3, 4};

    // unpack
    {
        test::_injection<0> f{};

        BOOST_HANA_RUNTIME_CHECK(equal(
            unpack(a, f),
            f(1)
        ));

        BOOST_HANA_RUNTIME_CHECK(equal(
            unpack(b, f),
            f(1, 2)
        ));

        BOOST_HANA_RUNTIME_CHECK(equal(
            unpack(c, f),
            f(1, 2, 3)
        ));

        BOOST_HANA_RUNTIME_CHECK(equal(
            unpack(d, f),
            f(1, 2, 3, 4)
        ));
    }
}
