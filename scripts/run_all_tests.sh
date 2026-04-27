#!/usr/bin/env bash
set -euo pipefail
pytest tests/integration
python tests/hardware_in_loop/step_response_test.py --sim
