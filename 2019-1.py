def solution(record):
    answer = []
    userDict = dict()
    chatLog = []
    enterMsg = "%s님이 들어왔습니다."
    exitMsg = "%s님이 나갔습니다."
    for info in record:
        infoLst = info.split(' ')
        if infoLst[0] == 'Enter':
            userDict[infoLst[1]] = infoLst[2]
            chatLog.append([enterMsg, infoLst[1]])
        elif infoLst[0] == 'Leave':
            chatLog.append([exitMsg, infoLst[1]])
        elif infoLst[0] == 'Change':
            userDict[infoLst[1]] = infoLst[2]
    for log in chatLog:
        answer.append(log[0] % userDict[log[1]])
    return answer
