def solution(answers):

    one = [1,2,3,4,5]
    two = [2,1,2,3,2,4,2,5]
    three = [3,3,1,1,2,2,4,4,5,5]

    result = {
        1: 0,
        2: 0,
        3: 0
    }

    for idx, val in enumerate(answers):

        if val == one[idx % len(one)]:
            result[1] += 1

        if val == two[idx % len(two)]:
            result[2] += 1

        if val == three[idx % len(three)]:
            result[3] += 1

    max_score = max(result.values())

    return [
        key
        for key, value in result.items()
        if value == max_score
    ]