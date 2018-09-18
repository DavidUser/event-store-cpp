# Zoop POS Tests

To run all tests at current directory use:

```
  make run
```

## Adding tests

1. Create any file with extension **.cc** in this directory.
2. Use the [Google Test Framework](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
    1. Include Google Test header 
    ```
    #include <gtest/gtest.h>
    ```
    2. Create a TEST function
    ```
    TEST(GroupOfTestsName, SpecificTestName {
      ...
    }
    ```
    3. ASSERT values
    ``` cpp
      EXPECT_TRUE(4 == 2+2);
    ```
