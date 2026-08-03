class Solution:
    def func(self, num: int) -> int:
        if num < 100:
            return 0
        
        s = str(num)
        n = len(s)
        dp = {}

        def solve(pos: int, prev_prev: int, prev: int, is_leading_zero: bool, is_part_equal: bool) -> tuple[int, int]:
            if pos >= n:
                return (1, 0)
            
            state = (pos, prev_prev, prev, is_leading_zero)

            if not is_part_equal and state in dp:
                return dp[state]
            
            total_numbers = 0
            total_wave_score = 0

            digit_limit = int(s[pos]) if is_part_equal else 9

            for digit in range(digit_limit + 1):
                is_new_leading_zero = is_leading_zero and (digit == 0)
                new_prev_prev = prev
                new_prev = -1 if is_new_leading_zero else digit

                rem_total_count, rem_total_score = solve(
                    pos + 1,
                    new_prev_prev,
                    new_prev,
                    is_new_leading_zero,
                    is_part_equal and (digit == digit_limit)
                )

                if not is_new_leading_zero and prev >= 0 and prev_prev >= 0:
                    is_peak = (prev > digit) and (prev > prev_prev)
                    is_valley = (prev < digit) and (prev < prev_prev)

                    if is_peak or is_valley:
                        total_wave_score += rem_total_count
                
                total_numbers += rem_total_count
                total_wave_score += rem_total_score

            if not is_part_equal:
                dp[state] = (total_numbers, total_wave_score)
            
            return (total_numbers, total_wave_score)

        _, total_wave_score = solve(0, -1, -1, True, True)

        return total_wave_score

    def totalWaviness(self, num1: int, num2: int) -> int:
        return self.func(num2) - self.func(num1 - 1)
