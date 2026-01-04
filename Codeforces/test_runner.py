import sys
import subprocess


def run_test(code_file, input_file, expected_output_file):
    """
    Runs the code with the given input and compares the output to the expected output.
    """
    try:
        # Read the input file
        with open(input_file, "r") as f:
            input_data = f.read()
    except FileNotFoundError:
        print(f"Error: Input file '{input_file}' not found.")
        return False

    try:
        # Run the code using python3
        result = subprocess.run(
            ["python3", code_file],
            input=input_data,
            text=True,
            capture_output=True,
            timeout=30,  # Timeout to prevent infinite loops
        )
    except subprocess.TimeoutExpired:
        print("Error: Code execution timed out.")
        return False
    except Exception as e:
        print(f"Error running code: {e}")
        return False

    if result.returncode != 0:
        print("Code execution failed with error:")
        print(result.stderr)
        return False

    actual_output = result.stdout.strip()

    try:
        # Read the expected output file
        with open(expected_output_file, "r") as f:
            expected_output = f.read().strip()
    except FileNotFoundError:
        print(f"Error: Expected output file '{expected_output_file}' not found.")
        return False

    # Compare outputs
    if actual_output == expected_output:
        print("✓ Test passed!")
        return True
    else:
        print("✗ Test failed!")
        print("Expected output:")
        print(repr(expected_output))
        print("Actual output:")
        print(repr(actual_output))
        return False


if __name__ == "__main__":
    if len(sys.argv) != 4:
        print(
            "Usage: python3 test_runner.py <code_file.py> <input_file> <expected_output_file>"
        )
        print("Example: python3 test_runner.py 2174A.py 2174A.in 2174A.out")
        sys.exit(1)

    code_file = sys.argv[1]
    input_file = sys.argv[2]
    expected_output_file = sys.argv[3]

    success = run_test(code_file, input_file, expected_output_file)
    sys.exit(0 if success else 1)
