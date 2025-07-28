from datetime import datetime, timedelta
from collections import defaultdict, deque


class LogDetails:
    def _init_(self, time, user, ipad, res):
        self.time = time
        self.user = user
        self.ipad = ipad
        self.res = res


def parse_time(time):
    return datetime.strptime(time, "%Y-%m-%dT%H:%M:%SZ")


def main():
    n = int(input())
    logs = []

    for _ in range(n):
        time, user, ipad, res = input().split()
        logs.append(LogDetails(time, user, ipad, res))

    violated = []

    user_failed = defaultdict(deque)
    ip_failed = defaultdict(deque)
    user_lockout = {}
    ip_blacklist = {}
    failed24 = defaultdict(int)
    sus_users = set()

    for log in logs:
        time = parse_time(log.time)
        user = log.user
        ip = log.ipad
        result = log.res

        if user in sus_users:
            violated.append(("SUSPENSION_VIOLATION", f"{log.time} {user} {ip}"))
            continue

        if user in user_lockout and time < user_lockout[user]:
            violated.append(("LOCKOUT_VIOLATION", f"{log.time} {user} {ip}"))
            continue

        if ip in ip_blacklist and time < ip_blacklist[ip]:
            violated.append(("BLACKLIST_VIOLATION", f"{log.time} {user} {ip}"))
            continue

        if result == "FAILURE":
            user_failed[user].append(time)
            if len(user_failed[user]) > 3:
                user_failed[user].popleft()
            if len(user_failed[user]) == 3 and (time - user_failed[user][0]).total_seconds() <= 300:
                user_lockout[user] = time + timedelta(seconds=300)

            ip_failed[ip].append(time)
            if len(ip_failed[ip]) > 5:
                ip_failed[ip].popleft()
            if len(ip_failed[ip]) == 5 and (time - ip_failed[ip][0]).total_seconds() <= 1200:
                ip_blacklist[ip] = time + timedelta(seconds=1800)

            failed24[user] += 1
            if failed24[user] == 10:
                sus_users.add(user)
        else:
            user_failed[user].clear()
            user_lockout.pop(user, None)

        for user in list(failed24.keys()):
            while user_failed[user] and (time - user_failed[user][0]).total_seconds() > 86400:
                user_failed[user].popleft()
                failed24[user] -= 1

    if not violated:
        print("NO_VIOLATION")
    else:
        for violation in violated:
            print(f"{violation[0]} {violation[1]}")


if _name_ == "_main_":
    main()