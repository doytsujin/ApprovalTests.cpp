#include "doctest/doctest.h"
#include "ApprovalTests/reporters/EnvironmentVariableReporter.h"

using namespace ApprovalTests;

TEST_CASE("When environment variable is not set, EnvironmentVariableReporter::report "
          "returns false")
{
    EnvironmentVariableReporter reporter;
    CHECK_FALSE(reporter.report("", "r.txt", "a.txt"));
}

TEST_CASE("When environment variable is invalid, EnvironmentVariableReporter::report "
          "returns false")
{
    EnvironmentVariableReporter reporter;
    CHECK_FALSE(reporter.report("INVALID_REPORTER", "r.txt", "a.txt"));
}