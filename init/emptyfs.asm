[org 0x0000]
;each sector holds 32 entries

;'header'
;cluster size is numer of 512 byte sectors
;cluster count is number of clusters from beginning of partition
;cluster size is minimum 4k
clustersize dq 8
clustercount dq 360

;file system entries
;stored as file number, chunk number

;first 32k (8 clusters) are bootsector and loader/kernel and are reserved
bootentries dq 0,0, 0,1, 0,2, 0,3, 0,4, 0,5, 0,6, 0,7

;next two entries are this table itself
fsentry dq 1,0, 1,1

;root directory entry
rootdir dq 2,0

times 348 dq -1

;eat up the remaining unused entries
;fill them with a known value to indicate unusable entries
times 138 dq 0xA5A5A5A5A5A5A5A5

;pointer to next fs table section (null since this is the one and only section)
nextfsentry dq 0,0
