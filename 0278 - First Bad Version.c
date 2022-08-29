// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int fBV(const int l, const int r)
{
    const int n = r - l;
    if (n <= 1) return r;
    int m = l + n / 2;
    if (isBadVersion(m))
        return fBV(l, m);
    else
        return fBV(m, r);
}

int firstBadVersion(int n)
{
    return fBV(0, n);
}