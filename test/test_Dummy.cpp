#include <boost/test/unit_test.hpp>
#include <can_common/Dummy.hpp>

using namespace can_common;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    can_common::DummyClass dummy;
    dummy.welcome();
}
