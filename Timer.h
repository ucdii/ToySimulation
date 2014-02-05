class Timer
{
public:

  /**
   * Start Time measurement
   */
	void start();

  /**
   * End Time measurement
   */
	void stop();

  /**
   * Get Execution time
   * @return long us (microseconds)
   */
	long getExecutionTime();

private:
	long startTime_;
	long executionTime_;
};

//static Timer myTimer;