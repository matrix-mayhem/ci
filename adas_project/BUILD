cc_library(
    name = "perception_lib",
    srcs = [
        "src/perception.cpp",
    ],
    hdrs = glob(["include/*.hpp"]),
    includes = ["include", "/usr/include/dlt"],
    linkopts = ["-ldlt"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "perception_main",
    srcs = ["src/main.cpp"],
    deps = [":perception_lib"],
    linkopts = ["-ldlt"],
)

cc_test(
    name = "test_perception",
    srcs = ["tests/test_perception.cpp"],
    deps = [
        ":perception_lib",
        "@com_google_googletest//:gtest",
        "@com_google_googletest//:gtest_main",
    ],
)

