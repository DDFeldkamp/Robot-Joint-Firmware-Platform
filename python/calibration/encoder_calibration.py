def compute_zero_offset(raw_samples):
    if not raw_samples:
        raise ValueError("Need at least one encoder sample")
    return sum(raw_samples) / len(raw_samples)
