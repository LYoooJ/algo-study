def solution(cacheSize, cities):
    answer = 0
    cache = []
    if cacheSize == 0:
        return len(cities) * 5
    for city in cities:
        city = city.lower()

        if city in cache:   # hit
            answer += 1
            cache.remove(city)
            cache.append(city)
        else:               # miss
            answer += 5
            if len(cache) < cacheSize:
                cache.append(city)
            else:
                cache.pop(0)
                cache.append(city)
    return answer