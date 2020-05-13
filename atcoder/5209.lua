local n, k = io.read('*n', '*n')
local mfl =  math.floor
local mod = 1000000007
local ans = 0
for i = k, n + 1 do
    local pre = mfl(i * (i - 1) / 2)
    local suf = mfl((n + n - i + 1) * i / 2)
    ans = (ans + suf - pre + 1) % mod
end
io.write(ans)