import numpy as np

def estimate_first_order_time_constant(times, positions, final_value):
    """Estimate time constant as first time reaching 63.2% of final value."""
    threshold = 0.632 * final_value
    for t, x in zip(times, positions):
        if x >= threshold:
            return t
    return np.nan
