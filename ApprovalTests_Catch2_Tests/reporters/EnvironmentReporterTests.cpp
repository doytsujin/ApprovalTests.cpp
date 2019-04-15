#include "Catch.hpp"

#include "ApprovalTests/SystemUtils.h"
#include "ApprovalTests/Approvals.h"
#include "ApprovalTests/reporters/BlockingReporter.h"

TEST_CASE("Blocks in this environment")
{
    auto machineName = SystemUtils::getMachineName();
    auto blocker = MachineBlocker::onMachineNamed(machineName);
    REQUIRE(blocker.isBlockingOnThisMachine() == true);
}

TEST_CASE("Does not block in this environment")
{
    auto machineName = SystemUtils::getMachineName();
    auto blocker = MachineBlocker::onMachinesNotNamed(machineName);
    REQUIRE(blocker.isBlockingOnThisMachine() == false);
}

// startcode machine_specific_test_runner
TEST_CASE("Only run this test on John's machine")
{
    auto blocker = MachineBlocker::onMachinesNotNamed("JOHNS_MACHINE");
    if ( blocker.isBlockingOnThisMachine() )
    {
        return;
    }
    // Write tests here that depend on John's environment.
    REQUIRE(SystemUtils::getMachineName() == "JOHNS_MACHINE");
}
// endcode
