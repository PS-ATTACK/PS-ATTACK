

import java.util.*;

class Pair{
    private int time;
    private int tmpTime;
    private int status;

    Pair(int time, int status) {
        this.time = time;
        this.status = status;
    }

    public int getTime(){
        return time;
    }

    public int getStatus(){
        return this.status;
    }
    public void setStatus(int status){
        if(this.status == 0){ this.status = status;  }
        else { this.status = this.status + status; }
    }
    public void setStatusM(int status, int time){
        if(status == 1){
            // status 0  일떈 그냥 tmp 에다가만 추가한다.
            this.tmpTime = time;
            this.status = status;
        }
        else {
            // status 1 이고 들어온 status 0 일때 현재시간 - tmptime을 해준다.
            //문제점 1 두번째 들어온다면 ? 그러면 세번째도 들어올수있다.
            this.time += time - this.tmpTime;
            this.status = status;
        }
    }
    public void setTime(int time){
        if(this.time == 0){ this.time = time; }
        else{ this.time = this.time + time; }
    }
    public void setTmpTime(int tmpTime){
        this.tmpTime = tmpTime;
    }
    public int getTemtime(){
        return this.tmpTime;
    }

}
class Solution{
    /**
     fees[0] //기본시간
     fees[1] //기본요금
     fees[2] //단위시간
     fees[3] //단위요금
     records
     "05:34 5961 IN",
     "06:00 0000 IN",
     "06:34 0000 OUT",
     "07:59 5961 OUT",
     "07:59 0148 IN",
     0148은 자동으로 23시59분에 출차
     */
    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};
        Map<String,Pair> hashMap = new LinkedHashMap<>();

        //init data 
        String[] dataSources = new String[3];
        for(String record : records){
            dataSources = record.split(" ",3); // limit = 3
            int thisTime = getMinutes(dataSources[0]);
            int thisStatus = dataSources[2].equals("IN") ? 1 : 0;
            if(hashMap.get(dataSources[1]) != null){
                // hashMap.get(dataSource[1]).setTime(thisTime); 
                // hashMap.get(dataSource[1]).setStatus(thisStatus); 
                hashMap.get(dataSources[1]).setStatusM(thisStatus,thisTime);
            }else{
                hashMap.put(dataSources[1],new Pair(0,0));
                hashMap.get(dataSources[1]).setStatusM(thisStatus,thisTime);
            }
        }
        // 나가지않은 차를 확인한다. 그리고 타임을 바꿔주고 status 도 바꿔준다.
        answer = new int[hashMap.size()];
        int i = 0;
        List<Map.Entry<String, Pair>> entries =
                new ArrayList<Map.Entry<String, Pair>>(hashMap.entrySet());
        Collections.sort(entries, new Comparator<Map.Entry<String, Pair>>() {
            public int compare(Map.Entry<String, Pair> a, Map.Entry<String, Pair> b){
                return a.getKey().compareTo(b.getKey());
            }
        });
        Map<String, Pair> sortedMap = new LinkedHashMap<String, Pair>();
        for (Map.Entry<String, Pair> entry : entries) {
            sortedMap.put(entry.getKey(), entry.getValue());
        }
        Iterator<String> it = sortedMap.keySet().iterator();
        while(it.hasNext()){
            String key = it.next();
            //tmp Time 에는 이미 들어가있는 상태 
            if(hashMap.get(key).getStatus() == 1){
                hashMap.get(key).setStatusM(0,1439);
            }
            double sTime = hashMap.get(key).getTime();
            if(sTime <= fees[0]){ sTime = fees[1];}
            else sTime = Math.ceil((sTime - fees[0]) / fees[2]) * fees[3] + fees[1];
            answer[i] = (int) sTime;
            i++;
        }
        return answer;

    }
    public static int getMinutes(String str){
        int time = 0;
        String[] data = str.split(":",2);

        return (Integer.parseInt(data[0]) * 60 ) + Integer.parseInt(data[1]);
    }

    
}