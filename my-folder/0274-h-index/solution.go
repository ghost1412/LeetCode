func hIndex(citations []int) int {
    sort.Ints(citations)
    for i:=0; i<len(citations); i++ {
        if len(citations) - i <=  citations[i] {
            return len(citations)-i
        }
    }
    return 0
}

// 0 1 3 5 6
